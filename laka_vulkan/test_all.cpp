/*
Copyright (c) 2018 gchihiha

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.

*/


#include "test.h"
#include "vk.h"

#include <vector>

#include "vk_mean.h"



#include <initializer_list>

using namespace std;
using namespace laka::vk;

//dfasdfsafds
class Test_fuck {
	void* pNext;
};

class Fuck1 :public Test_fuck {};
class Fuck2 :public Test_fuck {};
class Fuck3 :public Test_fuck {};

//fdsafsdfsd
void test_function(Test_fuck& t)
{
	
}

void test_all()
{
	Test_fuck fuck;
	Fuck1 fuck1;
	Fuck2 fuck2;
	Fuck3 fuck3;

	test_function(fuck1);

    init_show;

    show_info("ʵ���汾:{}", version_str(get_instance_version()));

	auto instance = Instance::get_new(
		{VK_KHR_SURFACE_EXTENSION_NAME,surface_extension_name}
	);

    show_info("ʵ�����:{}", (void*)instance->handle);
    show_info("�ռ����ص������ṹ��ָ��:{}", (void*)instance->allocator_callbacks_ptr);
    show_info("�����豸������:", instance->physical_device_groups.size());
    int index = 0;
    for (auto&& group:instance->physical_device_groups)
    {
        show_info("����{0}�������߼��豸�Ƿ�֧��ͨ��VkMemoryAllocateFlagsInfo��deviceMask��Ա���豸�Ӽ��Ϸ����豸�ڴ�: {1}\n�豸��:{2}", index++, group.properties.subsetAllocation == VK_TRUE ? "��" : "��", group.properties.physicalDeviceCount);

        for (int i = 0; i < group.properties.physicalDeviceCount; i++)
        {
            show_info(
                "\n�豸 {0} ��ʵ�ʾ��:{1}"
                "\n�豸 {0} �ı�����:{2}", 
                i,
                (void*)(group.properties.physicalDevices[i]),
                (void*)group.physical_devices[i]->handle
            );
        }
    }
    
    show_info("ȫ���豸��Ϣ:");
    index = 0;
    for (auto&& physical_device : instance->physical_devices)
    {
        show_info(
            "\n�豸{}��Ϣ:"
            "\n���:{}"
            "\n������:{}"
            "\n������Ϣ:", 
            index,
            (void*)physical_device.handle,
            physical_device.queue_familys.size()
        );

        for (auto&& qf : physical_device.queue_familys)
        {
            show_info(
                "\n����:{}"
                "\n������:{}"
                ,qf.index
                ,qf.properties.queueCount
            );
        }

        auto pd_lp = physical_device.get_layer_propertiess();
        show_info("�豸����Ϣ:");
        for (auto&& lp : *pd_lp)
        {
            show_info(mean(lp)->c_str());

            auto pd_ext = physical_device.get_extension_properties(lp.layerName);
            show_info("����չ��Ϣ:");
            for (auto&& ext : *pd_ext)
            {
                show_info(mean(ext)->c_str());
            }
        }

        show_info("�豸����:{}",mean(*physical_device.get_features())->c_str());

        //show_info("�豸����:{}", mean(*physical_device.get_properties())->c_str() );

        index++;
    }


    auto dc = instance->get_a_device_creator(
        [](Pramater_choose_physical_device& choose_pd)->bool {
        return true;
    }, 
        [](Pramater_choose_queue_family& choose_qf)->bool {
        for (auto&& qf_info : choose_qf.give_you_queue_family_info_)
        {
            User_choose_queue_info fuck;
            fuck.queue_family_index = qf_info.index;
            fuck.queue_priorities.resize(10);
            for (auto&& qp : fuck.queue_priorities)
            {
                qp = 1.0;
            }
            choose_qf.waiting_for_your_filled_info_.push_back(fuck);
        }
        return true;
    });

    auto device = dc->get_a_device(instance->physical_devices[0]);

    auto semaphore = device->get_a_semaphore();

    auto fence = device->get_a_fence();

    auto event_temp = device->get_a_event();

    auto buffer = device->get_a_buffer(
		2048, 
		Buffer::E_Create::E_sparse_residency 
		| Buffer::E_Create::E_sparse_binding, 
		Buffer::E_Usage::E_vertex_buffer 
		| Buffer::E_Usage::E_conditional_rendering, 
		VkSharingMode::VK_SHARING_MODE_BEGIN_RANGE, 
		{0,1}
	);


	








}