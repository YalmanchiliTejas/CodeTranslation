# -*- coding: utf-8 -*-
def main():
    n, x, m = map(int, input().split())
    a = [x]
    repeat_dic = {x: 0}
    cnt = 1
    repeat_start = -1
    repeat_end = -1
    for i in range(1, n):
        num = a[i-1] ** 2 % m
        a.append(num)
        if not num in repeat_dic.keys():
            repeat_dic[num] = cnt
            cnt += 1
        else:
            repeat_start = repeat_dic[num]
            repeat_end = i
            break
    if repeat_start == -1:
        ans = sum(a)
    else:
        nokori = n - repeat_start
        repeat_num = repeat_end - repeat_start
        q, mod = divmod(nokori, repeat_num)

        ans = sum(a[:repeat_start]) + q*sum(a[repeat_start:repeat_end]) + \
            sum(a[repeat_start: repeat_start + mod])
    # print(a)
    # print(q)
    # print(mod)
    # print(repeat_start)
    # print(repeat_end)
    print(ans)


if __name__ == "__main__":
    main()
