import collections
print(*sorted(eval("&".join(["collections.Counter('"+input()+"')"for i in range(int(input()))])).elements()),sep='')