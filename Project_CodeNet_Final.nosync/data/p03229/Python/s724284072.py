import itertools
import numpy as np
data_num = int(input()) 
data = [int(input()) for i in range(data_num)] 
#data_num=5
#data=[6,8,1,2,3]

data.sort()
npdata=np.array(data)

parts1=[1]
parts2=[2 for i in range(data_num-2)]
parts1.extend(parts2)
parts1.append(1)
npparts1=np.array(parts1)

parts0=[(-1)**(i+1) for i in range(data_num)]
npparts0=np.array(parts0)

y=npparts1*npparts0

y=y.tolist()
y.sort()

y=np.array(y)
z1=sum(data*y)

parts01=[(-1)**i for i in range(data_num)]
npparts0=np.array(parts01)

y=npparts1*npparts0

y=y.tolist()
y.sort()
y=np.array(y)
z2=sum(data*y)

print(max(z1,z2))
