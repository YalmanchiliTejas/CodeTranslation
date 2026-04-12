#n = int(input())
#n,k = map(int,input().split())
#x = list(map(int,input().split()))

r,g,b = input().split()

a = r+g+b
a = int(a)


if a%4==0:
    print("YES")
else:
    print("NO")
