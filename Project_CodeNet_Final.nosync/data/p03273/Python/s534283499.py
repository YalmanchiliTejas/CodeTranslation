hori_verti = input().split()
horisontal = int(hori_verti[0])
vertical = int(hori_verti[1])
input_grid = [input() for element in range(horisontal)]

remove_yoko_list = set()
remove_tate_list = set()

def scan(grid_verti_list):
  for ele in grid_verti_list:
    if ele != '.':
      return False
  return True

def scan_column():
  for tate in range(vertical):
    row = []
    for yoko in range(horisontal):
      row.append(input_grid[yoko][tate])
    if scan(row):
      remove_tate_list.add(tate)      

for hori_num in range(horisontal):
  grid_verti_list = input_grid[hori_num]
  if scan(list(grid_verti_list)):
    remove_yoko_list.add(hori_num)
    
scan_column()

res = []
for x in range(horisontal):
  keep = []
  if x in remove_yoko_list:
    continue
  for (y, letter) in enumerate(input_grid[x]):
    if y in remove_tate_list:
      continue
    keep.append(letter)
  res.append(keep)
      
result = []  
for str in res:
  new_line_list = ''.join(str)
  result.append(new_line_list)

if(len(result) == 0):
  print('\n'.join(input_grid))
else:
  print('\n'.join(result))