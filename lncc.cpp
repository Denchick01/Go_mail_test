#include <sys/stat.h>
#include <iostream>
#include <fstream>

int main (int argc, char** argv) 
{
    if (argc != 2) {
        std::cerr << "Invalid number of parameters\n";
        exit(2);
    }

    std::ifstream fin;
    fin.open(argv[1]);

    if (!fin.is_open()) {
         std::cerr << "Can't open file: " << argv[1] << "\n";
         exit(2);
    } 

    struct stat stbuff;
    stat(argv[1], &stbuff);

    if (stbuff.st_mode & S_IFDIR) {
        std::cout << argv[0] <<": " << argv[1] << "it is directory\n";
    }

    unsigned int line_count = 0;

    const std::size_t MAX_LENGTH = 256;
    char buff[MAX_LENGTH];
    
    for (std::size_t bit_num = fin.read(buff, MAX_LENGTH).gcount(); 
                     bit_num > 0; bit_num = fin.read(buff, MAX_LENGTH).gcount()) {
        for (size_t it_arr = 0; it_arr < bit_num; ++it_arr) {
             if (buff[it_arr] == '\n') {
                 ++line_count;
             }
         }
    }

    fin.close();

    std::cout << line_count << " " << argv[1] << "\n";

    return 0;
}




        
