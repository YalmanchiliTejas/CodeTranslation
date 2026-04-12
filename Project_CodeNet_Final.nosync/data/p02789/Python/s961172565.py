def main(test_case,clear_case):
    if test_case <= clear_case:
      return "Yes"
    else:
      return "No"
    
if __name__ == "__main__":
    input_num = input()
    num1 = int(input_num.split()[0])
    num2 = int(input_num.split()[1])
    print(main(num1,num2))