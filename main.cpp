#include <iostream>
#include "include/YUVImage.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    const char *url = "../resource/longmao_yuv420p.yuv";
    yuv420p_split(url, 450, 450);
    yuv420_gray(url, 450, 450);
    yuv420_half_y(url, 450, 450);

    const char *url2 = "../resource/longmao_yuv444p.yuv";
    yuv444_split(url2, 450, 450);
    yuv444_gray(url2, 450, 450);
    yuv444_half_y(url2, 450, 450);


    return 0;
}
