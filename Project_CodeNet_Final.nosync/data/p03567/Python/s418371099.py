S=input()

before=''
for s in S:
  if before+s=='AC':
    print('Yes')
    exit()
  before=s
print('No')