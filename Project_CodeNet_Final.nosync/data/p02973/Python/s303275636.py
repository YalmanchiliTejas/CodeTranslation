from sys import stdin
import bisect
def main():
    #入力
    readline=stdin.readline
    n=int(readline())
    a=[int(readline()) for _ in range(n)]

    li=[]
    for i in range(n):
        if i==0:
            li.append(a[i])
        else:
            l=-1
            r=len(li)
            while l<r-1:
                m=(l+r)//2
                if li[m]>=a[i]:
                    l=m
                else:
                    r=m
            if r==len(li):
                li.append(a[i])
            else:
                li[r]=a[i]

    print(len(li))
    
if __name__=="__main__":
    main()