#pragma once

/**
 * 分离YUV420P图像数据
 *
 * @param url yuv图像文件路径
 * @param w   指定yuv图像宽
 * @param h   指定yuv图像高
 * @return 处理成功返回0，否则返回-1
 */
int yuv420p_split(const char* url, int w, int h);

/**
 * 将YUV420P图像输出为灰度图
 *
 * @param url
 * @param w
 * @param h
 * @return
 */
int yuv420_gray(const char *url, int w, int h);

/**
 * YUV420P格式的图像降低一半亮度
 *
 * @param url
 * @param w
 * @param h
 * @return
 */
int yuv420_half_y(const char *url, int w, int h);

/**
 * 分离YUV444P图像数据
 *
 * @param url
 * @param w
 * @param h
 * @return
 */
int yuv444_split(const char *url, int w, int h);

/**
 * 将YUV444P图像输出为灰度图
 *
 * @param url
 * @param w
 * @param h
 * @return
 */
int yuv444_gray(const char *url, int w, int h);

/**
 *
 * YUV444P格式的图像降低一半亮度
 *
 * @param url
 * @param w
 * @param h
 * @return
 */
int yuv444_half_y(const char *url, int w, int h);
