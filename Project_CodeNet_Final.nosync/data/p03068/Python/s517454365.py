n = int(input())
s = input()
k = int(input())
x = s[k-1]
ans =[]
for i in s:
    if i == x:
        ans.append(i)
    else:
        ans.append('*')
print(''.join(ans))
