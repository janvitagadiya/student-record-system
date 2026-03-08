#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;

class student{
    int studentID;
    string Name;
    int marks;
    string department;

public:
    student(){}

    student(int id,string name,int marks,string dep){
        studentID = id;
        Name = name;
        this->marks = marks;
        department = dep;
    }

    void print(){
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Student Name: "<<Name<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<endl;
    }

    int Searchstudent(int id){
        if(studentID == id)
            return 1;
        return 0;
    }

    void update(int newMarks){
        marks = newMarks;
    }

    int getMarks(){
        return marks;
    }

    friend void sortstudent(student s[],int);
};

void sortstudent(student stu[],int k){
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k-i-1;j++){
            if(stu[j+1].getMarks() > stu[j].getMarks()){
                student temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }
}

int main(){

    int n,k=0,marks,id;
    string name,dep;

    student stu[1000];

    cout<<"Program Started"<<endl;

    while(true){

        cout<<"\nMENU\n";
        cout<<"1 Add student"<<endl;
        cout<<"2 Display students"<<endl;
        cout<<"3 Search student"<<endl;
        cout<<"4 Update student"<<endl;
        cout<<"5 Delete student"<<endl;
        cout<<"6 Sort students"<<endl;
        cout<<"7 Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>n;

        if(n==1){

            cout<<"Enter ID: ";
            cin>>id;

            cout<<"Enter Name: ";
            getline(cin>>ws,name);

            cout<<"Enter Marks: ";
            cin>>marks;

            cout<<"Enter Department: ";
            getline(cin>>ws,dep);

            stu[k++] = student(id,name,marks,dep);

            cout<<"Student added successfully\n";
        }

        else if(n==2){

            if(k==0){
                cout<<"No students found\n";
            }
            else{
                for(int i=0;i<k;i++){
                    cout<<"Details of student "<<i+1<<":\n";
                    stu[i].print();
                }
            }
        }

        else if(n==3){

            int found = 0;

            cout<<"Enter student ID to search: ";
            cin>>id;

            for(int i=0;i<k;i++){
                if(stu[i].Searchstudent(id)){
                    stu[i].print();
                    found = 1;
                    break;
                }
            }

            if(!found)
                cout<<"Student not found\n";
        }

        else if(n==4){

            int found = 0;

            cout<<"Enter ID to update: ";
            cin>>id;

            for(int i=0;i<k;i++){

                if(stu[i].Searchstudent(id)){

                    cout<<"Enter new marks: ";
                    cin>>marks;

                    stu[i].update(marks);

                    cout<<"Marks updated\n";

                    found = 1;
                    break;
                }
            }

            if(!found)
                cout<<"Student not found\n";
        }

        else if(n==5){

            int found = 0;

            cout<<"Enter ID to delete: ";
            cin>>id;

            for(int i=0;i<k;i++){

                if(stu[i].Searchstudent(id)){

                    for(int j=i;j<k-1;j++){
                        stu[j] = stu[j+1];
                    }

                    k--;

                    cout<<"Student deleted successfully\n";

                    found = 1;
                    break;
                }
            }

            if(!found)
                cout<<"Student not found\n";
        }

        else if(n==6){

            sortstudent(stu,k);

            cout<<"Students sorted by marks\n";
        }

        else if(n==7){

            cout<<"THANK YOU!\n";
            break;
        }

        else{
            cout<<"Invalid choice\n";
        }
    }

    return 0;
}