a = list(input())

for i in range(len(a)-1):
    if a[0]  != a[i+1]:
        print("Yes")
        break
    elif i == len(a)-2:
        print("No")