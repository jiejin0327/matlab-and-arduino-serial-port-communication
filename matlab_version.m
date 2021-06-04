clear all;

%%connect to arduino
x = serial('COM9','BAUD', 9600);
fopen(x);

while(fscanf(x) ~='f') %fscanf:receive data from arduino
end
disp('arduino connect success !')

%%
go = true;
a= input('Press 1 to up\n 2 to down \n 3 to right\n 4 to left : ');
fprintf(x,a); % fprintf(arduino,data) : send data to arduino

%%
while go
    while(a == 0 | fscanf(x) ~='f') 
    % if input a=0,disconnecct the arduino 
    % when arduino has finished moving,arduino will send message 'f' to matlab
    end
    disp('arduino has finished moving');
    a= input('Press 1 to up\n 2 to down \n 3 to right\n 4 to left : ');
    fprintf(x,a);
    if (a == 0)
        go=false;
    end
end
fclose(instrfind); % disconnecct the arduino
