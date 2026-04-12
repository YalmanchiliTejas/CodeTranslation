a=input()
num=1
for i in range(len(a)-1):
    if a[i]==a[i+1]:
        num+=1
if num==len(a):
    print("No")
else:
    print("Yes")

# if a[0]==a[1] and a[1]==a[2]:
#     print("No")
# else:
#     print("Yes")