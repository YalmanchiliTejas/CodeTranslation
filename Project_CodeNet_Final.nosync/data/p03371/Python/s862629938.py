A,B,C,X,Y=map(int,input().split())

C*=2

tmp = max([X,Y])
result = 1e10
for i in range(tmp+1):
    current = C*i+max([0,A*(X-i)])+max([0, B*(Y-i)])
    if result>current:
        result = current
print(result)
