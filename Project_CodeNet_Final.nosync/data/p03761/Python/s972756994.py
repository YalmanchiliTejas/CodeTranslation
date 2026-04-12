import string
n = int(input())
ans = {'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,
      'm':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,
      'y':0,'z':0}
for i in range(n):
    if i == 0:
        st = input()
        for j in st:
            ans[j] += 1
    else:
        tmp = {'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,
      'm':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,
      'y':0,'z':0}
        st = input()
        for j in st:
            tmp[j] += 1
            
        for j in tmp:
            ans[j] = min(ans[j],tmp[j])

anser = ''
for d in string.ascii_lowercase:
    for j in range(ans[d]):
        anser += d
print(anser)