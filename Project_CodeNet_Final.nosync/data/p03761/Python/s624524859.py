import string
atoz = string.ascii_lowercase
N = int(input())
azcount = {}
for i in range(N):
  s = input()
  for alph in atoz:
    if alph in azcount:
      azcount[alph] = min(s.count(alph), azcount[alph])
    else:
      azcount[alph] = s.count(alph)
res = ''

for alph in atoz:
  res += alph * azcount[alph]

print(res)