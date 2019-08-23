#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <algorithm>
#include <string>
#include <dirent.h>
#include <vector>

using namespace std;

int main ()
{
    ofstream out("real.txt");
    struct dirent *ptr;
    DIR *dir;
    string PATH = "/home/uisee/Data/image_capturer_0";
    dir=opendir(PATH.c_str());
    vector<string> files;
    while((ptr=readdir(dir))!=NULL)
    {
        if(ptr->d_name[0] == '.')
            continue;
        files.push_back(ptr->d_name);
    }
    sort(files.begin(),files.end());
    for(int i = 0;i<files.size();i++)
    {
        out << files[i] << std::endl;
    }
    closedir(dir);
    return 0;
}
//#include <iostream>
////#include <opencv2/core.hpp>
////#include <opencv2/highgui.hpp>
//#include <fstream>
//#include <string>
//#include <cassert>
//#include <sstream>
////#include <Eigen/Core>

////#include <Eigen/Dense>
////#include <Eigen/Geometry>
//#include <fstream>
//using namespace std;
/////using namespace Eigen;

//int main(int argc, char** argv)
//{
//    if(argc != 2)
//    {
//        std::cout<<"This progress used for gerenate vslam_log."<<std::endl;
//        std::cout<<"Parameter: "<<std::endl;
//        std::cout<< " [folder]: ref_pose.txt folder "<<std::endl;
//        return  0;
//    }

//   string path = argv[1];

//   string ref_pose_name=path+"ref_pose.txt";
//   string vslam_log_name=path+"vslam_log.txt";
//   string str,res;

//   ifstream f;
//   ifstream fin;
//   fin.open("/home/uisee/workspace/EfficientLargeScaleStereo/stereo.txt");
//   ofstream of;
//   f.open(ref_pose_name.data());
//   of.open(vslam_log_name);
//   assert(f.is_open());

//   if(!f.is_open())
//   {
//       std::cout<<ref_pose_name<<std::endl;
//       std::cout<<vslam_log_name<<std::endl;
//   }

//   while(getline(f,str))
//   {
//     stringstream line;
//     line<<str;

//     string img_name;

//     fin>>img_name;

//     line>>res;
//     string x=res;
//     line>>res;
//     string y=res;
//     line>>res;

//     line>>res;
//     line>>res;
//     line>>res;
//     string heading=res;
//     double head=atof(heading.c_str());

//     head += 1.57079633;
////     if(head > M_PI)
////        head -= 2*M_PI;
////     else if(head < -M_PI)
////        head += 2*M_PI;

//     heading=to_string(head);
//     //line>>res;
//     string time;
//     time.resize(14);
//     for(int i=0;i<10;i++)
//     {
//         time[i]='1';
//     }
//     time[10]='.';
//     for(int i=11;i<14;i++)
//     {
//         time[i]='1';
//     }
//     string year="2017",month="10",day="10",hour="10",minute="10",sec="10.324";

//     of<<img_name<<"@"<<time<<"@"<<heading<<"@"<<    x<<"@"<<y<<"@4"<<"@"<<year<<"."<<month<<"."<<day<<"."<<hour<<":"
//      <<minute<<":"<<sec<<endl;
//   }
//   f.close();
//   of.close();


//    std::cout<<"done! "<<std::endl;

//    return 0;
//}

