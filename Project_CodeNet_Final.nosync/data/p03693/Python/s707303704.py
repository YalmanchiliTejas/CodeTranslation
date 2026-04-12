#coding:utf-8

if __name__ == "__main__":
    num_list = input().split(" ")
    num = int("".join(num_list))

    if num % 4 == 0:
        print("YES")
    else:
        print("NO")
