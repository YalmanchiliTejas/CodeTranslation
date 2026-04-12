c=s=0
for a in[*open(0)][1].split():a=int(a);c+=s*a;s+=a
print(c%(10**9+7))