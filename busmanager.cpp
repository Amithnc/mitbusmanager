#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <termios.h>
using namespace std;
int n ;
struct bus_struct
{
    char ind[5], bus_no[10],src[25], dest[25], max_seat[5], seats_avail[5],stops[20][20];
    //string stops[100];
};
class Bus
{
private:
    char ind[5], bus_no[10],src[25], dest[25], max_seat[5], seats_avail[5],stops[20][20];
    //string stops[100];
    char buffer[110];
    int bus_index,i;
    void read()
    {
        cout<<"\t\t\t\t\t\t\t";cout << "bus number : ";
        cin >> bus_no;
        cout<<"\t\t\t\t\t\t\t";cout << "Source : ";
        cin >> src;
        cout<<"\t\t\t\t\t\t\t";cout << "Destination : ";
        cin >> dest;
        cout<<"\t\t\t\t\t\t\t";cout << "Maximun Seats : ";
        cin >> max_seat;
        cout<<"\t\t\t\t\t\t\t";cout<<"enter the number of stops:";
        cin>>n;
        cout<<"\t\t\t\t\t\t\t";cout<<"enter  "<<n<<"  stops :\n";
        cout<<"\t\t\t\t\t\t\t";
        for(i=0;i<n;i++)
        {
          cin>>stops[i];
          cout<<"\t\t\t\t\t\t\t";
        }
    }

public:
    Bus()
    {
        char extra[110], ind[5];
        int index_temp = 0;
        fstream file;
        file.open("bus.txt", ios::in);
        if (file)
        {
            while (!file.eof())
            {
                file.getline(ind, 5, '|');
                file.getline(extra, 110, '\n');
                index_temp++;
            }
        }
        bus_index = index_temp;
        file.close();
    }
    void add()
    {
        fstream record, index_by_src_dest;
        record.open("bus.txt", ios::out | ios::app);
        index_by_src_dest.open("bus_index_by_src_dest.txt", ios::out | ios::app);
        read();
        strcpy(buffer, bus_no);strcat(buffer, "|");
        strcat(buffer, src);strcat(buffer, "|");
        strcat(buffer, dest);strcat(buffer, "|");
        strcat(buffer, max_seat);strcat(buffer, "|");
        for(i=0;i<n;i++)
        {
          strcat(buffer,stops[i]);
          strcat(buffer, "|");
        }
        bus_index++;
        record << bus_index << "|";
        index_by_src_dest << bus_no << "|" << src << "|" << dest << "|" << bus_index << "\n";
        strcat(buffer, "\n");
        record.write(buffer, strlen(buffer));
        record.close();
        cout<<"record added Successfully"<<endl;
    }
     void display()
    {
        if (bus_index > 0)
        {
            char extra[100];
            fstream file;
            file.open("bus.txt", ios::in);
            cout<<"\t\t\t";cout << "+---------------+---------------+---------------+---------------+---------------+-------+-------+---------------+\n";
            cout<<"\t\t\t";cout << "|bus No.\t|Source\t\t|Destination\t|stops|\n";
            cout<<"\t\t\t";cout << "+---------------+---------------+---------------+---------------+---------------+-------+-------+---------------+\n";
            while (!file.eof())
            {
                file.getline(ind, 5, '|');
                file.getline(bus_no, 10, '|');
                file.getline(src, 25, '|');
                file.getline(dest, 25, '|');
                file.getline(max_seat, 4, '|');
                //file.getline(seats_avail, 4, '|');
                for(i=0;i<n;i++)
                {
                    file.getline(stops[i],40, '|');
                }
                file.getline(extra, 100, '\n');
                if (strlen(bus_no) > 0){
                    cout<<"\t\t\t";cout << "|" << bus_no << "\t\t\t|" << src << "\t\t|" << dest << "\t\t\t|";
                    for(i=0;i<n;i++)
                    {
                       cout<<stops[i]<<"\t";
                    }
                }cout<<"\n";
            }
            cout<<"\t\t\t";cout << "+---------------+---------------+---------------+---------------+---------------+-------+-------+---------------+\n";
            file.close();
        }
        else
        {
            cout<<"\t\t\t\t\t\t\t";cout << "No Aeroplanes\n";
        }
    }
};    
void admin()
{
   struct bus_struct temp;
   char bus_no[10];
   int ch = 0;
   do
   {
        Bus bus = Bus();
        cout<<"\t\t\t\t\t\t\t";cout << "+----------------------------------+\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|              ADMIN               |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "+----------------------------------+\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|1:add bus                         |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|2:Display bus Details             |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|3:Display Passengers Details      |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|5:Log Out                         |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "+----------------------------------+\n";
        cout<<"\t\t\t\t\t\t\t";cout << "Enter your choice : ";
        cin >> ch;

        system("clear");
        switch (ch)
        {
        case 1:
            bus.add();
            break;
        case 2:
            bus.display();
            break;
        /*case 3:
            cout<<"\t\t\t\t\t\t\t";cout << "Enter Aeroplane Number : ";
            cin >> aeroplane_no;
            temp = aeroplane.get_aeroplane_details(aeroplane_no);
            if (strcmp(temp.aeroplane_no, aeroplane_no) == 0)
                b.display_by_aeroplane_no(aeroplane_no);
            else {
                cout<<"\t\t\t\t\t\t\t";cout << "Invalid Aeroplane number\n";
            }
            //getche();
            break;*/
        default:
            cout<<"\t\t\t\t\t\t\t";cout << "Thank You";
            return;
        }
        cout << endl;
    } while (1);
    return;
}
void student()
{







}
int main(int argc, char const *argv[])
{
    int ch = 0,k=-1;
    int i;
    int no_stu=4;
    char sname[20],pass[20];
    char admin_pass[20]="test";
    char student_name[4][20]={"student1","student2","student3","student4"};
    char student_pass[4][20]={"pass1","pass2","pass3","pass4"};
    do
    {

        //system("clear");
        cout<<"\t\t\t\t\t\t\t";cout << "+------------------------------+\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|       MIT BUS MANAGER        |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "+------------------------------+\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|1:Administrator               |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|2:student                     |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "|3:Exit                        |\n";
        cout<<"\t\t\t\t\t\t\t";cout << "+------------------------------+\n";
        cout<<"\t\t\t\t\t\t\t";cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout<<"\t\t\t\t\t\t\t";cout << "Enter Admin Password : ";
            cin >> pass;
            if(strcmp(pass,admin_pass)==0)
            {
                cout<<"\t\t\t\t\t\t\t";cout<<"Log In Successful\n";
                admin();
            }
            else
            {
                cout<<"\t\t\t\t\t\t\t";cout<<"Inavlid Password\n";
            }
            break;
        case 2:
            cout<<"\t\t\t\t\t\t\t";cout << "Enter student name : ";cin>>sname;
            for(i=0;i<no_stu;i++)
            {
                if(strcmp(student_name[i],sname)==0)
                {
                    k=i;
                    break;
                }
            }
            if(i>=no_stu)
            {
                cout<<"\t\t\t\t\t\t\t";cout<<"Invalid student name\n";
                break;
            }
            cout<<"\t\t\t\t\t\t\t";cout<<"Enter Password : ";cin>>pass;
            if(strcmp(student_pass[k],pass)==0)
            {
                cout<<"\t\t\t\t\t\t\t";cout<<"Log In Successful\n";
                student();
            }
            else
            {
                cout<<"\t\t\t\t\t\t\t";cout<<"Invalid Password\n";
            }
            
            break;
        default:
            cout<<"\t\t\t\t\t\t\t";cout << "Thank You\n";
            return 0;
        }
        cout << endl;
    } while (1);
    return 0;
}