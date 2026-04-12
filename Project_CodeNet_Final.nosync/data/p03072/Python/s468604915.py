I=lambda:int(input())
L=lambda:list(map(int,input().split()))
def main():
    n=I()
    h=L()
    ans=1
    maxi=h[0]
    for i in range(1,n):
        if h[i]>=maxi:
            maxi=h[i]
            ans+=1
    print(ans)

if __name__ == '__main__':
    main()