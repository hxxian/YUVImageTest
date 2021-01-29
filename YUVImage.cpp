


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int yuv420p_split(const char *url, int w, int h) {
    FILE *fp;
    if (fopen_s(&fp, url, "rb+") != 0) {
        printf("The file open faild!");

        return -1;
    }

    FILE *fp1, *fp2, *fp3;
    errno_t err1, err2, err3;

    err1 = fopen_s(&fp1, "../out/longmao_420_y.y", "wb+");
    err2 = fopen_s(&fp2, "../out/longmao_420_u.y", "wb+");
    err3 = fopen_s(&fp3, "../out/longmao_420_v.y", "wb+");

    if (err1 != 0 || err2 != 0 || err3 != 0) {
        printf("err1: %d, err2: %d, err3: %d", err1, err1, err3);
        return -1;
    }

    unsigned char *pic = (unsigned char *) malloc(w * h * 3 / 2);

    fread(pic, 1, w * h * 3 / 2, fp);
    // Y
    fwrite(pic, 1, w * h, fp1);
    // U
    fwrite(pic + w * h, 1, w * h / 4, fp2);
    // V
    fwrite(pic + w * h * 5 / 4, 1, w * h / 4, fp3);

    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}


int yuv420_gray(const char *url, int w, int h) {
    FILE *fp;
    if (fopen_s(&fp, url, "rb+") != 0) {
        printf("The file open faild!");

        return -1;
    }

    FILE *fp1;
    if (fopen_s(&fp1, "../out/longmao_420p_gray.yuv", "wb+") != 0) {
        printf("output file not exist!");
        return -1;
    }

    unsigned char *pic = (unsigned char *) malloc(w * h * 3 / 2);

    fread(pic, 1, w * h * 3 / 2, fp);
    memset(pic + w * h, 128, w * h / 2);
    fwrite(pic, 1, w * h * 3 / 2, fp1);

    free(pic);
    fclose(fp);
    fclose(fp1);
    return 0;
}


int yuv420_half_y(const char *url, int w, int h) {
    FILE *fp;
    if (fopen_s(&fp, url, "rb+") != 0) {
        printf("The file open faild!");

        return -1;
    }

    FILE *fp1;
    if (fopen_s(&fp1, "../out/longmao_420p_half.yuv", "wb+") != 0) {
        printf("output file not exist!");
        return -1;
    }

    unsigned char *pic = (unsigned char *) malloc(w * h * 3 / 2);
    fread(pic, 1, w * h * 3 / 2, fp);

    for (int j = 0; j < w * h; j++) {
        // 亮度减半，直接对Y分量除以2就行
        unsigned char temp = pic[j] / 2;
        pic[j] = temp;
    }

    fwrite(pic, 1, w * h * 3 / 2, fp1);

    free(pic);
    fclose(fp);
    fclose(fp1);

    return 0;
}


int yuv444_split(const char *url, int w, int h) {
    FILE *fp;
    if (fopen_s(&fp, url, "rb+") != 0) {
        printf("The file open faild!");

        return -1;
    }

    FILE *fp1, *fp2, *fp3;
    errno_t err1, err2, err3;

    err1 = fopen_s(&fp1, "../out/longmao_444_y.y", "wb+");
    err2 = fopen_s(&fp2, "../out/longmao_444_u.y", "wb+");
    err3 = fopen_s(&fp3, "../out/longmao_444_v.y", "wb+");

    if (err1 != 0 || err2 != 0 || err3 != 0) {
        return -1;
    }

    unsigned char *pic = (unsigned char *) malloc(w * h * 3);


    fread(pic, 1, w * h * 3, fp);
    //Y
    fwrite(pic, 1, w * h, fp1);
    //U
    fwrite(pic + w * h, 1, w * h, fp2);
    //V
    fwrite(pic + w * h * 2, 1, w * h, fp3);

    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}


int yuv444_gray(const char *url, int w, int h) {
    FILE *fp;
    if (fopen_s(&fp, url, "rb+") != 0) {
        printf("The file open faild!");

        return -1;
    }

    FILE *fp1;
    if (fopen_s(&fp1, "../out/longmao_444p_gray.yuv", "wb+") != 0) {
        return -1;
    }

    unsigned char *pic = (unsigned char *) malloc(w * h * 3);


    fread(pic, 1, w * h * 3, fp);
    memset(pic + w * h, 128, w * h * 2);
    fwrite(pic, 1, w * h * 3, fp1);


    free(pic);
    fclose(fp);
    fclose(fp1);
    return 0;
}


int yuv444_half_y(const char *url, int w, int h) {
    FILE *fp;
    if (fopen_s(&fp, url, "rb+") != 0) {
        printf("The file open faild!");

        return -1;
    }

    FILE *fp1;
    if (fopen_s(&fp1, "../out/longmao_444p_half.yuv", "wb+") != 0) {
        return -1;
    }

    unsigned char *pic = (unsigned char *) malloc(w * h * 3);


    fread(pic, 1, w * h * 3, fp);

    for (int j = 0; j < w * h; j++) {
        unsigned char temp = pic[j] / 2;
        pic[j] = temp;
    }

    fwrite(pic, 1, w * h * 3, fp1);


    free(pic);
    fclose(fp);
    fclose(fp1);

    return 0;
}