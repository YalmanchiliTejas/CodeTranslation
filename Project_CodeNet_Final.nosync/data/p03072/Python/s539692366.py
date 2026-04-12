# coding:utf-8
def main():
    n = int(input())
    l = list(map(int, input().split()))
    count = 1

    #対象の山
    for i in range(1,n):
        view = True
        #比較される山
        for j in range(0,i):
            if l[j] > l[i]:
                view = False
        if view == True:
            count = count + 1

    print(count)

if __name__ == '__main__' :
    main()