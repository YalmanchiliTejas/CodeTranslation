n = int(input())
str = input()
remained_str = str[ int(input()) - 1 ]

ans = ''
for s in str:
  if( s == remained_str ):
    ans += s
  else:
    ans += '*'
print(ans)