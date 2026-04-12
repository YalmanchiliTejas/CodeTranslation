n = int(input())
  
meal_price = n * 800
meal_discount_count = n // 15
  
print (meal_price - (meal_discount_count * 200))