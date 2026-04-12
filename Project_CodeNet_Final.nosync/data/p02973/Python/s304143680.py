def main():
    from bisect import bisect_right
    n=int(input())
    a=[int(input()) for _ in range(n)]

    color=[]
    for i in range(n-1,-1,-1):
        num=a[i]
        idx=bisect_right(color,num)
        if idx==len(color):
            color.append(num)
        else:
            color[idx]=num
    
    print(len(color))    
if __name__=='__main__':
    main()