a = int(input())
b = input()
c = int(input())

ans = b
for i in range(a):
  if(b[i] != b[c - 1]):
    ans = ans.replace(b[i],'*')
print(ans)