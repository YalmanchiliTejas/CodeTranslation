# coding:utf-8

def main():
    N = int(input())
    S = input()
    K = int(input())
    change = S[K-1]
    # print(change)
    str_list = list(S)
    ans = []
    for i in str_list:
        if i != change:
            ans.append("*")
        else:
            ans.append(i)
    str_changed = "".join(ans)
    print(str_changed)


if __name__ == "__main__":
    main()