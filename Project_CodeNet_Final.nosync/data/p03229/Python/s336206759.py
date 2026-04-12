n = input()
arr = []
for i in range(n):
    arr.append(input())
arr.sort()
if n % 2 == 0:
    arr1 = arr[0:n/2]
    arr2 = arr[n/2:n]
    n1 = arr1[-1]
    n2 = arr2[0]
    arr1.remove(n1)
    arr2.remove(n2)
    print (sum(arr2)-sum(arr1)) * 2 + n2 - n1
else:
    arr1 = arr[0:n/2]
    arr2 = arr[n/2+1:n]
    n1 = arr1[-1]
    n2 = arr2[0]
    n3 = arr[n/2]
    arr1.remove(n1)
    arr2.remove(n2)
    print (sum(arr2)-sum(arr1)) * 2 + n2 - n1 + max(n2-n3,n3-n1)