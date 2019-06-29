#include <iostream>
#include <fstream>
using namespace std;

ifstream win("/Users/WT20181105881/Desktop/tin.txt");
ifstream jin("/Users/WT20181105881/Desktop/fin.txt");
ofstream wout("/Users/WT20181105881/Desktop/tout.txt");

int k=1;
class Person{
    string school,num,name;
    double score[7]={0};
public:
    double sum=0,max=0,min=0,average=0;
    Person(string s,string nu,string na);
    ~Person();
    void display(string judge[]);
};

void Person::display(string judge[]){
    wout<<"第"<<k<<"名"<<endl;
    wout<<school<<" "<<num<<" "<<name<<endl;
    for(int i=0;i<7;i++){
        wout<<judge[i]<<" "<<score[i];
        if(i!=6)    wout<<" ";
    }
    wout<<endl;
    wout<<name<<"的平均分为"<<average<<"分"<<endl;
    wout<<endl;
    k++;
}

Person::Person(string s,string nu,string na):school(s),num(nu),name(na){
    for(int i=0;i<7;i++){
        jin>>score[i];
        sum+=score[i];
        if(i==0){
            max=score[i];
            min=score[i];
        }
        else{
            if(score[i]>max) max=score[i];
            if(score[i]<min) min=score[i];
        }
    }
    sum-=(max+min);
    average=sum/5.0;
}

int main(){
    int n;
    string school,num,name,judge[7];
    win>>n;
    Person *per[n];
    
    for(int i=0;i<7;i++)
        jin>>judge[i];
    for(int i=0;i<n;i++){
        win>>school>>num>>name;
        per[i] = new Person(school,num,name);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(per[j]->average<per[j+1]->average){
                Person *tper=per[j+1];
                per[j+1]=per[j];
                per[j]=tper;
            }
        }
    }
    for(int i=0;i<n;i++)
        per[i]->display(judge);
}
