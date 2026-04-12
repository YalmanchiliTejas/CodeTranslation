class Pizza:
  def __init__(self, price, count = 0):
    self.price = price
    self.count = count
    
  def count_pay(self):
  	return self.price * self.count
  
  def add_count(self,n):
    self.count += n
    if self.count <= 0:
      self.count = 0
      
A, B, C, X, Y = map(int, input().split())
P_A = Pizza(A,X)
P_B = Pizza(B,Y)
P_AB = Pizza(C)

i = 0
pay_list = []
while i <= max(X, Y):
  pay = P_A.count_pay() + P_B.count_pay() + P_AB.count_pay()
  pay_list.append(pay)
  P_A.add_count(-1)
  P_B.add_count(-1)
  P_AB.add_count(2)
  i += 1

print(min(pay_list))