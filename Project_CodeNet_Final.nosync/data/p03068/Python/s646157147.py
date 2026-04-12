n = int(input())
s = input()
k = int(input())

# k番目の文字と異なる文字をすべて*で置き換える
t = s[k-1]
r = ""
for i in s:
  if i not in t:
    r = r + "*"
  else:
    r = r + i
    
print(r)