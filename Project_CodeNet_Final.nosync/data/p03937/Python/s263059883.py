# 2019/08/16

h,w=map(int,input().split())
w+=2
a=[['.']*w]
for i in range(h):
    a+=[['.']+list(input())+['.']]

a+=[['.']*w]

g=(h,w-2)
cnt=0

i,j=1,1
while i<h or j<w:
    a[i][j]='@'
    if a[i-1][j]=='#' or a[i][j-1]=='#':
        ans='Impossible'
        break

    if (i,j)==g:
        ans='Possible'
        break
        
    if (a[i+1][j]=='#')^(a[i][j+1]=='#'):
        if a[i+1][j]=='#':
            i+=1
        else:
            j+=1
    else:
        ans='Impossible'
        break

print(ans)