obj = pthread.o  #相当于宏定义

pthread:$(obj)
	gcc -ggdb3 -Wall -o  pthread $(obj) -lpthread

pthread.o:pthread.c 
	gcc -c $<   #-I后是需要头文件的路径

.PHONY:clean
clean:
	rm $(obj)
	
.PHONY:cleanall
cleanall:
	rm $(obj) pthread




