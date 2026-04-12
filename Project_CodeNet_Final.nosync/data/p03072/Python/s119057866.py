#coding:utf-8

def main():
    N = int(input())
    H = list(map(int, input().split()))
    num = 0
    border = 0
    for i in range(N):
        if H[i] - border >= 0:
            num += 1
            border = H[i]

    print(num)

if __name__ == "__main__":
    main()