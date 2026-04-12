a=s=0
for x in map(int,[*open(0)][1].split()):a+=s*x;s+=x
print(a%(10**9+7))