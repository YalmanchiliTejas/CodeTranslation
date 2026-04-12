bus_services=input()

service=False
for i in range(len(bus_services)-1):
  if bus_services[i]!=bus_services[i+1]:
    service=True
if service==True:
  print('Yes')
else:
  print('No')