#agc007a

h,w=map(int,raw_input().split())
cnt=0
for i in range(h):
 cnt+=raw_input().count('#')
if cnt==h+w-1:
 print 'Possible'
else:
 print 'Impossible'
