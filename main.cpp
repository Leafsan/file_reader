#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream inputFile( "../stageData.txt", ifstream::binary);
    inputFile.seekg(0, ifstream::end);
    int fileSize = static_cast<int>(inputFile.tellg());
    inputFile.seekg(0, ifstream::beg);
    char* fileImage;
    try
    {
        fileImage = new char[fileSize];
    }
    catch(const std::bad_alloc& e)
    {
        cout << "There is no file." << endl;
        return 1;
    }
    inputFile.read(fileImage, fileSize);
    cout.write(fileImage, fileSize);

    return 0;
}