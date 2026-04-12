n,x = map(int,input().split())
ans =0
while x > 0:
    if n==0:
        ans +=1
        break
    elif x == 1:
        break
    elif x >=2**(n+1)-1:
        ans += 2**n
        x -=2**(n+1)-1
        n -=1
    elif x == 2**(n+1)-2:
        ans += 2**n-1
        print(ans)
        exit()
    else:
        n -=1
        x -=1
print(ans)