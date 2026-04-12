a,b,c,x,y = map(int, input().split())

arr = []
for i in range(10**5+1):
    arr.append(i*2*c + max(0,x-i)*a + max(0,y-i)*b)

print(min(arr))
