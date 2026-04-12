# coding:utf-8

def main():
    N = int(input())
    mountain = input().split()
    #print(mountain)
    ans = 0
    mountain_max = -1
    for i in range(N):
        if mountain_max <= int(mountain[i]):
            mountain_max = int(mountain[i])
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()