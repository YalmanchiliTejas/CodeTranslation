
import sys
sys.setrecursionlimit(10 ** 5 + 10)
input = sys.stdin.readline
import bisect




def main():
    num = int(input())
    data = [int(input()) for i in range(num)]

    now_list = [-1 for i in range(num)]

    for i in range(num):
        ind = bisect.bisect_left(now_list, data[i])
        now_list[ind - 1] = data[i]

    count = 0
    for i in range(num):
        if now_list[i] >= 0 :
            count += 1

    print(count)




if __name__ == '__main__':
    main()