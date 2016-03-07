//
//  main.cpp
//  1111
//
//  Created by 何灏 on 16/3/7.
//  Copyright © 2016年 UESTCOpenSource. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
const int nu=100;//不能改变其值的变量
enum Sex{Man,Woman,mid};//枚举类型
class Stuinf{//新建一个学生信息的类
private:
    string Name;
    string Num;
    enum Sex sex;//自己定义的枚举数据类型
    int Age;
    string Address;
    string Phone;
    Stuinf *next;//带的指针
public://各种成员函数
    //类的初始化函数
    Stuinf(){Name="no name";Num="no num";sex=mid;Age=0;Address="no address";Phone="no phone";next=NULL;}
    
    void setname(){cout<<"输入姓名"<<endl;cin>>Name;}
    string getname(){return Name;}
    
    void setnum(){cout<<"输入学号"<<endl;cin>>Num;}
    string getnum(){return Num;}
    
    void setsex(){int x;cout<<"输入0或1，0代表男性，1代表女性"<<endl;cin>>x;sex=(x==0)?Man:Woman;}
    string getsex(){return (sex==Man)?"Man":"Woman";}
    
    void setage(){cout<<"输入年龄"<<endl;cin>>Age;while(!(0<Age&&Age<100)){cout<<"输入错误，请重输"<<endl;cin>>Age;}}
    int getage(){return Age;}
    
    void setaddress(){cout<<"输入地址"<<endl;cin>>Address;}
    string getaddress(){return Address;}
    
    void setphone(){cout<<"输入电话号码"<<endl;cin>>Phone;}
    string getphone(){return Phone;}
    //指针指向下一个结点
    void setnext(Stuinf *stu){next=stu;}
    Stuinf* getnext(){return next;}
    //类的析构函数
    ~Stuinf(){};
};

//主函数
int main(){
    Stuinf *head=new Stuinf();//新建一个空对象
    Stuinf *st[nu];
    int i;
    int n;
    cout<<"请输入指令 0,1,2,3,4,5"<<endl;
    cout<<"0、退出通讯录系统"<<endl;
    cout<<"1、 录入功能：用于增加通信录的内容，即首次录入同学的相关信息。";
    cout<<"性别的输入应是男或"<<" 女，如果输入错误，请重新输入；";
    cout<<"输入的年龄应在0~100之间，否则重新输入。"<<endl;
    cout<<"2、 插入功能：用于随时增加一个同学的相关信息。"<<endl;
    cout<<"3、 删除功能：用于随时删除一个同学的相关信息。"<<endl;
    cout<<"4、 查找功能：可以分别通过姓名、性别、年龄、地址、邮编和联系电话查找某个同学的信息。"<<endl;
    cout<<"5、 修改功能：通过姓名查找，然后写成完成姓名、性别、年龄、地址、邮编、联系电话等信息的修改。"<<endl;
    cout<<"请输入:"<<endl;
    cin>>n;
    while(!(0<=n&&n<6)){
        cout<<"输入0到6的数字"<<endl;
        cin>>n;
    }
    while(n){
        switch (n){
            case 1:{
                int num;
                cout<<"请输入需要录入的学生人数"<<endl;
                cin>>num;
                
                for(i=0;i<num;i++){
                    st[i]=new Stuinf();
                    st[i]->setname();
                    st[i]->setage();
                    st[i]->setnum();
                    st[i]->setphone();
                    st[i]->setaddress();
                    st[i]->setsex();
                    st[i]->setnext(head->getnext());
                    head->setnext(st[i]);
                }
                break;
            }
            case 2:{
                Stuinf* p;
                p=new Stuinf();
                p->setname();
                p->setage();
                p->setnum();
                p->setphone();
                p->setaddress();
                p->setsex();
                p->setnext(head->getnext());
                head->setnext(p);
                break;
            }
            case 3:{
                string number;
                cout<<"输入要删除的学生学号"<<endl;
                cin>>number;
                Stuinf* p;Stuinf* q;
                p=head;
                if(head->getnext()==NULL) cout<<"通讯录为空"<<endl;
                while(p->getnum()!=number){
                    q=p;
                    p=p->getnext();
                }
                 if(p->getnext()==NULL)
                    cout<<"该学生不存在"<<endl;
                else{
                    q->setnext(p->getnext());
                    p->~Stuinf();
                    cout<<"学号为"<<number<<"的学生已经删除"<<endl;
                }
                break;
            }
            case 4:{
                string na;
                cout<<"请输入姓名"<<endl;
                cin>>na;
                Stuinf * p=head->getnext();
                while(p){
                    if(p->getname()==na) break;
                    p=p->getnext();
                }
                if(p==NULL) cout<<"该学生不存在"<<endl;
                else{
                    cout<<"学生信息:"<<endl;
                    cout<<"姓名:"<<p->getname()<<endl;
                    cout<<"学号:"<<p->getnum()<<endl;
                    cout<<"年龄:"<<p->getage()<<endl;
                    cout<<"地址:"<<p->getaddress()<<endl;
                    cout<<"性别:"<<p->getsex()<<endl;
                    cout<<"电话号码:"<<p->getphone()<<endl;
                }
                break;
            }
            case 5:{
                string na;
                cout<<"请输入姓名"<<endl;
                cin>>na;
                Stuinf * p=head->getnext();
                while(p){
                    if(p->getname()==na) break;
                    p=p->getnext();
                }
                if(p==NULL) cout<<"该学生不存在"<<endl;
                else{
                    cout<<"修改姓名"<<endl;
                    p->setname();
                    cout<<"修改学号"<<endl;
                    p->setnum();
                    cout<<"修改年龄"<<endl;
                    p->setage();
                    cout<<"修改地址"<<endl;
                    p->setaddress();
                    cout<<"修改性别"<<endl;
                    p->setsex();
                    cout<<"修改电话号码"<<endl;
                    p->setphone();
                    cout<<"修改完毕"<<endl;
                }
                break;
            } 
        }
        cout<<"请输入指令 0,1,2,3,4,5"<<endl;
        cout<<"0、退出通讯录系统"<<endl;
        cout<<"1、 录入功能：用于增加通信录的内容，即首次录入同学的相关信息。"; 
        cout<<"性别的输入应是男或女，如果输入错误，请重新输入；";
        cout<<"输入的年龄应在0~100之间，否则重新输入。"<<endl;
        cout<<"2、 插入功能：用于随时增加一个同学的相关信息。"<<endl;
        cout<<"3、 删除功能：用于随时删除一个同学的相关信息。"<<endl;
        cout<<"4、 查找功能：可以分别通过姓名、性别、年龄、地址、邮编和联系电话查找某个同学的信息。"<<endl;
        cout<<"5、 修改功能：通过姓名查找，然后写成完成姓名、性别、年龄、地址、邮编、联系电话等信息的修改。"<<endl;
        cout<<"请输入:"<<endl;
        cin>>n;
    }
}