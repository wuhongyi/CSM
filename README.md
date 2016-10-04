<!-- README.md --- 
;; 
;; Description: 
;; Author: Hongyi Wu(吴鸿毅)
;; Email: wuhongyi@qq.com 
;; Created: 日 10月  2 13:34:54 2016 (+0800)
;; Last-Updated: 二 10月  4 14:34:04 2016 (+0800)
;;           By: Hongyi Wu(吴鸿毅)
;;     Update #: 6
;; URL: http://wuhongyi.github.io -->

# README

Author: Hongyi Wu(吴鸿毅)、Chenyang Niu(牛晨阳)、Chuan Xu(徐川)

本小程序用来批量计算，自动寻找 Wc 当前仅适用于小范围。

详细请访问网站：http://ns.ph.liv.ac.uk/~esp/nuclear/WS/

## 程序简要介绍

- 说明
   - README.md
- 核心计算程序
   - pssketch_header
   - hfbc.exe
   - jxgamma.exe
   - pskc.exe
   - spag2psk.exe
   - swgamma.exe
- 批量处理
   - AutomaticRun.cc
   - AutomaticSearch.cc
   - input.txt
   - wuReadData.hh
- bat脚本
   - clean.BAT
   - loop.BAT

----

## 运行

**AutomaticRun.cc 程序仅适用于windows系统下运行**

编译软件 CodeVlocks 网址: http://www.codeblocks.org/downloads/binaries  选择版本 **codeblocks-XX.XXmingw-setup.exe**(其中XX为版本号)

编译 **AutomaticRun.cc**得到 AutomaticRun.exe，然后修改输入卡 input.txt ，之后执行 AutomaticRun.exe。

将该文件夹移到 Linux 系统，用ROOT 编译 AutomaticSearch.cc 然后即可执行。


<!-- README.md ends here -->
