// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <strsafe.h>
using namespace std;
using namespace cv;
ofstream myfile;
void showimg(char* path) {
	Mat img = imread(path, 1);
	//if (countNonZero(img)) {
		double minval, maxval;
		Point minloc, maxloc;
//		minMaxLoc(img, &minval, &maxval, &minloc, &maxloc);
		cout << img.size().width << 'x' << img.size().height  << endl;
		myfile <<path<<endl<< img.size().width << 'x' << img.size().height << endl;
		//namedWindow(path, WINDOW_NORMAL);
		imshow(path, img);
	//}
}
int main()
{
	WIN32_FIND_DATA file;
	auto path = L"d:\318\*";
	TCHAR cpath[260];
	myfile.open("images.txt");
	
	
	_tcscpy_s(cpath, _countof(cpath),_T("testfolder\\*.jpg"));
	file.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
	//TCHAR szDir[260];
	//StringCchCopy(szDir, 260, cpath);
	
	std::wcout << cpath << std::endl;
	HANDLE search_handle = FindFirstFile(cpath, &file);
	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			char  fullpath[260] = "testfolder/";
			std::wcout << file.cFileName << std::endl;
			char path[260];
			sprintf_s(path, "%ws", file.cFileName);
			strcat_s(fullpath, path);
			showimg(fullpath);
		} while (FindNextFile(search_handle, &file));
		FindClose(search_handle);

	}
	
	waitKey(0);
	myfile.close();
    return 0;
}


