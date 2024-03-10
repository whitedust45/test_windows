//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//double answer(double H,double h)//2007.1
//{
//    if(h==0)return H;
//    return H+ answer(H/2,--h);
//}
//class Cpoint{//2007.2
//public:
//    Cpoint(double a=0,double b=0):x(a),y(b){};
//    ~Cpoint(){};
//    double dist(const Cpoint& a,const Cpoint &b)const{
//        double ans = sqrt(pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2));
//        return ans;
//    }
//    double get_x()const{
//        return x;
//    }
//    double get_y()const{
//        return y;
//    }
//
//private:
//    double x;
//    double y;
//};
//Cpoint operator-(const Cpoint&a,const Cpoint&b){
//    return Cpoint(a.get_x()-b.get_x(),a.get_y()-b.get_y());
//}
//
//class CTriangle{
//public:
//    CTriangle(Cpoint a,Cpoint b,Cpoint c): m_a(a), m_b(b), m_c(c){}
//    bool is90()const{
//        double edge1=Cpoint().dist(m_a,m_b);
//        double edge2=Cpoint().dist(m_a,m_c);
//        double edge3=Cpoint().dist(m_c,m_b);
//        double zhou = edge1+edge2+ edge3;
//        double long_edge = max(max(edge2,edge1),edge3);
//        double short_edge = min(min(edge2,edge1),edge3);
//        double middle_edge = zhou -long_edge-short_edge;
//        if(pow(short_edge,2)+pow(middle_edge,2)== pow(long_edge,2))return true;
//        else return false;
//    }
//    Cpoint m_a,m_b,m_c;
//};
//
//int main() {
//    double H=0,h=0;
//    cout<<"please press H";
//    cin>>H;
//    cout<<"please press h";
//    cin>>h;
//    cout<<answer(H,h)<<endl;
//    return 0;
//}
