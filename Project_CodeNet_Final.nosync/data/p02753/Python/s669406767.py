s = input().split()
x1=s[0][0]
x2=s[0][1]
x3=s[0][2]
flag = False
A = 'A'
B = 'B'
if x1==A and x2==A and x3==A:
    flag = True
elif x1==B and x2==B and x3==B:
    flag = True
else:
    flag = False
if (flag):
    result = 'No'
else:
    result = 'Yes'
print(result)