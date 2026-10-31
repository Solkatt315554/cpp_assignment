# C++ Group Assignment
> 小组作业仓库(Git for C++ group assignment)

## Information of members 
| name     |  ID      | work part                                   |branch name                                       |
|----------|----------|---------------------------------------------|--------------------------------------------------|
|YAN XUHAN |SWE2609068|1.Read the employee list; 2.Stastics function|1.feature_stastics                                |
|YANG JIAXI|SWE2609069|1.Add function 2.Dipaly table function       |1.feature_add 2.feature_display                   |
|Hiba      |SWE2609024|1.Search employee 2.Delete 3.Update          |1.feature_search 2.feature_delete 3.feature_update|

##  项目简介
一个员工名单管理系统，展示员工的各项信息，可查找，可加入，可删除，可编辑。

 
## Some Rules must be followwed
1. Please do NOT write your own part in the main file.Always write in your branches.
2. Please do NOT modify any thing in main.cpp, for restoration:
> git checkout origin/main -- main.cpp
2. The way to name branches:**feature-xxx**
4. Please always remark what you write
5. Please do NOT put exe files and any other file which is not end up with .cpp into the file when PR 

## Instructon 
 1. 先拉最新main( pull the newest main )
>git pull origin main
 2. 新建自己功能分支( build the new branch)
>git checkout -b feature_add_staff
 3. 在 staff.h staff.cpp 这些文件里写功能，不要改main.cpp （ do NOT modify main.cpp）
 4. 写完 (when finshi)
>git add .

>git commit -m "这个就是写批注 feat: (write down the remark)"

>git push origin feature-add-staff

 5. 在网页点 Compare & pull request 发起PR ( PR on website )