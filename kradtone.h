#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#define MAX_TONES 32
#define KRADTONE_DEFAULT_VOLUME 65

typedef struct {
	float frequency;
	float delta;
	float angle;
	int active;
} tone_t;

typedef struct {

	int s;
	tone_t tones[MAX_TONES];
	int active_tones;
	float sample_rate;
	int volume;
	float volume_actual;
	
} kradtone_t;

kradtone_t *kradtone_create(float sample_rate);
void kradtone_add(kradtone_t *kradtone, float frequency);
void kradtone_add_preset(kradtone_t *kradtone, char *preset);
void kradtone_clear(kradtone_t *kradtone);
void kradtone_volume(kradtone_t *kradtone, int volume);
void kradtone_remove(kradtone_t *kradtone, float frequency);
void kradtone_run(kradtone_t *kradtone, float *buffer, int samples);
void kradtone_destroy(kradtone_t *kradtone);
