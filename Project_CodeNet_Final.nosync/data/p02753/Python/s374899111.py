def InS(): return input()


def InL(): return list(map(int, input().split()))


def InI(): return int(input())


S = input()

S_list = list(S)


if S_list[0] == S_list[1]:
    if S_list[1] == S_list[2]:
        print("No")
    else:
        print("Yes")
else:
    print("Yes")