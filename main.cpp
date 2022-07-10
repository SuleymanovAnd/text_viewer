#include <iostream>
#include <fstream>
int main() {

    std::cout << "Enter file path:" << std::endl;
    std::string path;
    std::getline(std::cin,path)  ;

    std::ifstream file;
    file.open (path,std::ios::binary);
    // проверка открылся ли файл
    while  ( !file.is_open ()){
        std::cout << "Enter correct file path:" << std::endl;
        std::cin >> path;
        file.open (path,std::ios::binary);
    }
    //
    char buffer [100];
    int size = 100;
    while (!file.eof()){
        if (size > 0){
            file.read (buffer, size);
            size = (int)file.gcount ();
        } else {break;}

        for( int i =0; i<size;i++){ // вывод
            std::cout << buffer [i];
        }
    }
    file.close();
}
