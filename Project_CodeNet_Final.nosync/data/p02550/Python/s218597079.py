N,X,M = map(int,input().split())
array = [0,X]
array2 = [X]
a = X
sum = X
valid = True
while(True):
    a = pow(a,2,M)
    if a in array2:
        y = array2.index(a)
        break
    sum += a
    array.append(sum)
    array2.append(a)
l = len(array2)
h = l - y
if N <= y:
    print(array[N])
else:
    ans = array[y] + (array[-1]-array[y])*((N-y)//h) + array[y+(N-y)%h] - array[y]
    print(ans)
