# -*- coding: utf-8 -*-

def main():
    while 1:
        n = int(input())
        if n == 0:
            return 0
        s_l = []
        for _ in range(n):
            s_l.append(int(input()))
        ans = int((sum(s_l) - max(s_l) - min(s_l))/(n-2))
        print(ans)

if __name__ == "__main__":
    main()

