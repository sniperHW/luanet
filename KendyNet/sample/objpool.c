#include "kn_time.h"
#include "kn_objpool.h"

int main(){
	int *array[1000000];
	allocator_t _allocator = NULL;//objpool_new(sizeof(int),1000000);
	int j = 0;
	uint32_t tick = kn_systemms();
	for(; j < 10;++j){	
		int i = 0;
		for(;i < 1000000;++i){
			//array[i] = calloc(1,sizeof(int));//CALLOC(_allocator,1);
			array[i] = CALLOC(_allocator,1,1);
		}
		i = 0;
		for(;i < 1000000;++i){
			//free(array[i]);
			FREE(_allocator,array[i]);
		}
	}
	printf("%u\n",kn_systemms()-tick);
	return 0;
}