def main(a, b):
  if a<b:
    print 'a < b'
  elif a>b:
    print 'a > b'
  else:
    print 'a == b'

input_string = raw_input()
input_list = input_string.split(' ')
a = int(input_list[0])
b = int(input_list[1])
main(a, b)