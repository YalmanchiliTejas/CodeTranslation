n = int(input())
line=list(map(int,input().split( )))

mod = 1000000007

sq_line=[i*i for i in line]

s=sum(line)
t=sum(sq_line)

print(((s*s-t)//2)%mod)